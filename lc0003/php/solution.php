<?php

class Solution
{
    function lengthOfLongestSubstring(string $s): int
    {
        $dict = [];
        $len = 0;
        $maxlen = 0;

        $left = 0;
        $right = 0;

        while ($right < strlen($s)) {
            while ($dict[$s[$right]] > 0) {
                $dict[$s[$left++]]--;
                $len--;
            }

            $dict[$s[$right++]]++;
            $len++;

            $maxlen = max($maxlen, $len);
        }

        return $maxlen;
    }
}
