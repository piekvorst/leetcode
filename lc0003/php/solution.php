<?php

class Solution
{
    function lengthOfLongestSubstring(string $s): int
    {
        $dict = [];
        $len = 0;

        $left = 0;
        $right = 0;

        while ($right < strlen($s)) {
            if (isset($dict[$s[$right]]))
                $left = max($left, $dict[$s[$right]] + 1);

            // invariant: s on [left; right] is unique

            $len = max($len, $right - $left + 1);

            $dict[$s[$right]] = $right;
            $right++;
        }

        return $len;
    }
}
