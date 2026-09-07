<?php

require __DIR__ . '/solution.php';

$f = function(string $name, array $nums, int $target, array $want) {
    $got = (new Solution())->twoSum($nums, $target);
    if ($got !== $want) {
        fwrite(STDERR, $name . ': unexpected value: ' . print_r($got, true));
        exit(1);
    }
};

$f('example1', [2, 7, 11, 15], 9, [0, 1]);
$f('example2', [3, 2, 4], 6, [1, 2]);
$f('example3', [3, 3], 6, [0, 1]);
