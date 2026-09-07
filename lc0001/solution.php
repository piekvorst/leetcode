<?php

class Solution
{
    function twoSum(array $nums, int $target): array
    {
        $dict = [];
        foreach ($nums as $i => $n) {
            if (isset($dict[$target - $n]))
                return [$dict[$target - $n], $i];

            $dict[$n] = $i;
        }

        throw new Exception();
    }
}
