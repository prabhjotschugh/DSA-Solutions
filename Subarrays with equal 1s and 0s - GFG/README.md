# Subarrays with equal 1s and 0s
## Medium
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array containing 0s and 1s. Find the number of&nbsp;subarrays having equal number of 0s and 1s. </span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><strong><span style="font-size:18px">Input:
</span></strong><span style="font-size:18px">n = 7
A[] = {1,0,0,1,0,1,1}
<strong>Output: </strong>8<strong>
Explanation: </strong></span><span style="font-family:arial,helvetica,sans-serif"><span style="font-size:18px">The index range for the 8 
sub-arrays are: (</span></span><span style="font-family:arial,helvetica,sans-serif"><span style="font-size:18px">0, 1), (2, 3), (0, 3), (3, 4), 
(4, 5) ,</span></span><span style="font-family:arial,helvetica,sans-serif"><span style="font-size:18px">(2, 5), (0, 5), (1, 6)</span></span></pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><strong><span style="font-size:18px">Input:
</span></strong><span style="font-size:18px">n = 5
A[] = {1,1,1,1,0}
<strong>Output: </strong>1<strong>
Explanation: </strong></span><span style="font-family:arial,helvetica,sans-serif"><span style="font-size:18px">The index range for the 
subarray is (3,4).</span></span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>countSubarrWithEqualZeroAndOne()</strong>&nbsp;which takes the array arr[] and the size of the array as inputs and returns the number of subarrays with equal number of 0s and 1s.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(n).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(n).</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= n&nbsp;&lt;= 10<sup>6</sup><br>
0 &lt;= A[i] &lt;= 1</span></p>
</div>