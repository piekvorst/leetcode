#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FS "		"

int mem[1000001];

enum ObjectType
{
	FACTORY = 1,
	ROBOT,
};

enum Direction
{
	NEUTRAL,
	LEFT_DIR,
	RIGHT_DIR,
};

struct Object
{
	enum ObjectType type;
	int x;
	enum Direction dir;
	int limit;
};
typedef struct Object Object;

void
dbg1(int *arr, int n)
{
	for (int *p = arr; p != arr+n; ++p)
		printf(FS "%d", *p);

	printf("\n");
}

void
dbg2(int **arr, int n)
{
	for (int **p = arr; p != arr+n; ++p)
		printf(FS "[%d %d]", (*p)[0], (*p)[1]);

	printf("\n");
}

int
cmprobots(const void *vp1, const void *vp2)
{
	int r1 = *(const int *)vp1;
	int r2 = *(const int *)vp2;

	if (r1 < r2) return -1;
	else if (r1 > r2) return 1;
	else return 0;
}

int
cmpfactories(const void *vp1, const void *vp2)
{
	int *f1 = *(int **)vp1;
	int *f2 = *(int **)vp2;

	if (f1 < f2) return -1;
	else if (f1 > f2) return 1;
	else return 0;
}

int
cmpobjects(const void *vp1, const void *vp2)
{
	Object o1 = *(Object *)vp1;
	Object o2 = *(Object *)vp2;

	if (o1.x < o2.x) return -1;
	else if (o1.x > o2.x) return 1;

	// "The positions of each robot are unique. The positions of
	// each factory are also unique. Note that a robot can be in the
	// same position as a factory initially."
	else if (o1.type == FACTORY) return -1;
	else return 1;

}

Object *
objmake(int *robots, int nrobots, int **factories, int nfactories)
{
	Object *objs;
	objs = calloc(nrobots + nfactories, sizeof(*objs));
	Object *op = objs;

	for (int *rp = robots; rp != robots+nrobots; ++rp)
		*(op++) = (Object){.type = ROBOT, .x = *rp};

	for (int **fp = factories; fp != factories+nfactories; ++fp)
		*(op++) = (Object){.type = FACTORY, .x = (*fp)[0], .limit = (*fp)[1]};

	return objs;
}

void
objdbg(Object *objs, int nobjs)
{
	for (Object *p = objs; p != objs+nobjs; ++p) {
		switch (p->type) {
		case FACTORY:
			printf(FS "[%d %d]", p->x, p->limit);
			break;
		case ROBOT:
			switch (p->dir) {
			case NEUTRAL:
				printf(FS "%d", p->x);
				break;
			case LEFT_DIR:
				printf(FS "←%d", p->x);
				break;
			case RIGHT_DIR:
				printf(FS "%d→", p->x);
				break;
			}
			break;
		}
	}

	printf("\n");
}

int
limitsum(Object *objs, int nobjs)
{
	int sum = 0;

	for (Object *op = objs; op != objs+nobjs; ++op) {
		if (op->type == FACTORY)
			sum += op->limit;
	}

	return sum;
}

Object *
leftfactory(Object *objs, int nobjs)
{
	for (Object *op = objs+nobjs-1; op != objs-1; --op) {
		if (op->type == FACTORY && op->limit != 0)
			return op;
	}

	return NULL;
}

Object *
rightfactory(Object *objs, int nobjs)
{
	for (Object *op = objs; op != objs+nobjs; ++op) {
		if (op->type == FACTORY && op->limit != 0)
			return op;
	}

	return NULL;
}

// To tell which object follows another, we need to put them together in
// one array.
//
// . . . R 1 R 1 . . .
//
// Which direction must the second R go? Right. Why? To make the first
// R's distance shorter. By what means can the second R identify it?
//
// sum(factories(arr[:i])) - sum(robots(arr[:i]))
//
// It means "on the left, how much limit is there once all robots
// repaired". If that number is -1, going to the left forces robots on
// the left to travel more distance.
//
// But what if the number is positive on both sides? According to the
// problem constraints, it's possible. Well, that means that both sides
// could take care of themselves regardless of that robot, thus go to
// the nearest one factory.
//
// FLAW
//
// R:	. . . . . R R . R . . . R R . . .
// F:	. . . 1 2 . . . R . . . 2 1 . . .
//
// The robot must go to the right. But it's not obvious.
//
// Suppose we start from the robot in the middle. Is it true that
// choosing either direction leads to the same total distance?
//
// Left:  4 (middle) + 4 (left) + 2 (right)
// Right: 4 (middle) + 3 (left) + 2 (right)
//
// Observation #0: the closest left/right factory doesn't tell anything,
// it can be emptied in the process.
//
// Observation #1: if it's possible to take either direction, it's
// impossible to tell in advance which group (left or right) would be
// harmed more.
//
// Observation #2: if it's possible to take either direction, and wait
// until all robots on the left and right sides repair, which direction
// will be cheaper.
//
// Observation #3: is it a halting problem?
//
// Wikipedia:
//
// "The halting problem is the problem of determining, from a
// description of an arbitrary computer program and an input, whether
// the program will finish running."
//
// Two differences:
//
// 1. The "description" is hidden. Its only property is that it results
// in the minimal distance.
//
// 2. It's guaranteed that the program will always finish.
void
identifydirs(Object *objs, int nobjs)
{
	int verbose = 1;

	for (Object *op = objs; op != objs+nobjs; ++op) {
		if (op->type == ROBOT) {
			int left = limitsum(objs, op-objs);
			int right = limitsum(op+1, objs+nobjs-op);

			if (verbose)
				printf("identifydirs:%s%d%s%d%s%d\n", FS, op->x, FS, left, FS, right);

			Object *lf = leftfactory(objs, op-objs);
			Object *rf = rightfactory(op+1, objs+nobjs-op);

			if (!lf || left < 0) op->dir = RIGHT_DIR;
			else if (!rf || right < 0) op->dir = LEFT_DIR;
			else if (abs(lf->x - op->x) < abs(rf->x - op->x)) op->dir = LEFT_DIR;
			else op->dir = RIGHT_DIR;
		}
	}
}

// Font
// R:	. . . x x . .
// F:	. . 1 1 . . .
// In this case, it's irrelevant for the first robot which factory to take.
//
// Font
// R:	. . . R R . . . R . . . R R . . .
// F:	. . . 2 1 . . . R . . . 2 1 . . .
//
// The robot must go to the right. Quite easy to detect if we remove the
// second robot in the beginning.
void
removerobotsonfactories(Object *objs, int nobjs, Object **out, int *nout)
{
	int removed = 0;

	Object *latestfactory = NULL;

	for (Object *op = objs; op != objs+nobjs; ++op) {
		switch (op->type) {
		case FACTORY:
			latestfactory = op;
			(*out)[(*nout)++] = *op;
			break;
		case ROBOT:
			if (latestfactory != NULL && op->x == latestfactory->x)
				--(latestfactory->limit);
			else
				(*out)[(*nout)++] = *op;

			break;
		}
	}
}

// What about first repairing robots with distance = 0, then 1, etc.?
//
// R:	. R . . . . . R . . . . . . .
// F:	. . . . . . 1 . 1 . . . . . .
//
// The robot in the middle must go left. sum(left) < sum(right).
//
// R:	. R . . . . . R . . R . . . .
// F:	. . . . . . 2 . 1 . . . . . .
//
// R:	. R . . . . . R . . R . . . .
// F:	. . . . . . 1 . 2 . . . . . .
//
// Now left and right. sum(left) vs sum(right).
//
// If both factories had limit=2, it'd be irrelevant.
//
// R:	. R . . . . . R . . R . . . .
// F:	. . . . . 2 . . 1 . . . . . .
//
// Now the middle R must go left.
//
// Observation #[0-9]: it's not about finding the closest factory.
//
// In fact, it is, but only when there are no conflicts.
//
//int
//removerobots(Object *objs, int nobjs, int targetdistance, Objects **out)
//{
//	int nout = 0;
//
//	for (Object *op = objs; op != objs+nobjs; ++op) {
//		if (op->type == FACTORY) {
//			(*out)[nout++] = op;
//			continue;
//		}
//
//		Object *left = leftfactory(objs, op-objs);
//		Object *right = rightfactory(op+1, objs+nobjs-op);
//
//		if (left == NULL && right == NULL) {
//			abort();
//		} else if (left == NULL) {
//			if (abs(right->x - op->x) == targetdistance)
//				--(right->limit);
//			else
//				(*out)[nout++] = op;
//
//			continue;
//		} else if (right == NULL) {
//			if (abs(left->x - op->x) == targetdistance)
//				--(left->limit);
//			else
//				(*out)[nout++] = op;
//
//			continue;
//		}
//
//		int leftsum = limitsum(objs, op-objs);
//		int rightsum = limitsum(op+1, objs+nobjs-op);
//	}
//
//	return removed;
//}

int
simulate(Object *objs, int nobjs)
{
	int distance = 0;

	for (Object *op = objs; op != objs+nobjs; ++op) {
		if (op->type != ROBOT)
			continue;
	}

	return distance;
}

long long
minimumTotalDistance(int *robots, int nrobots, int **factories, int nfactories, int *mfactories)
{
	memset(mem, 0, sizeof(mem));

//	qsort(robots, nrobots, sizeof(*robots), cmprobots);
//	qsort(factories, nfactories, sizeof(*factories), cmpfactories);

	dbg1(robots, nrobots);
	dbg2(factories, nfactories);

	Object *objs = objmake(robots, nrobots, factories, nfactories);
	int nobjs = nrobots+nfactories;
	qsort(objs, nobjs, sizeof(*objs), cmpobjects);

	int newlen = 0;
	removerobotsonfactories(objs, nobjs, &objs, &newlen);
	nobjs = newlen;

	identifydirs(objs, nobjs);
	objdbg(objs, nobjs);

	return simulate(objs, nobjs);
}
