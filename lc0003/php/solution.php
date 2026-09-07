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
                $left = $dict[$s[$right]] + 1;

            $dict[$s[$right]] = $right;
            $right++;

            $len = max($len, $right - $left);
        }

        return $len;
    }
}
