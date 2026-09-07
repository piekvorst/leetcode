<?php

require __DIR__ . '/solution.php';

$f = function(string $name, string $s, int $want) {
    $got = (new Solution())->lengthOfLongestSubstring($s);
    if ($got !== $want) {
        fwrite(STDERR, $name . ': unexpected value: ' . print_r($got, true));
        exit(1);
    }
};

$f('example1', 'abcabcbb', 3);
$f('example2', 'bbbbb', 1);
$f('example3', 'pwwkew', 3);
$f('wronanswer1', 'ccbbcc', 2);
