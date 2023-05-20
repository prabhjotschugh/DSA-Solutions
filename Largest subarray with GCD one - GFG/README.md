# Largest subarray with GCD one
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array with n elements. Find length of the largest sub-array having GCD equal to 1. If no such &nbsp;subarray exist with&nbsp;GCD 1, return&nbsp;-1.</span><br>
<br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong>: n = 3, arr = [1, 3, 5]
<strong>Output:</strong>&nbsp;3&nbsp;
<strong>Explanation</strong>: GCD of 1, 3 and 5
is equal to 1.So the length is 3. </span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>n = 3,<strong> </strong>arr = [2, 4, 6]
<strong>Output:&nbsp;</strong>-1
<strong>Explanation</strong>: No such &nbsp;subarray exist.
</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You dont need to read input or print anything. Complete the function <strong>findLargestSubarray</strong><strong>()&nbsp;</strong>which takes array <strong>arr</strong>&nbsp;of length <strong>n</strong>&nbsp;as input parameter and returns&nbsp;the<strong>&nbsp;</strong>length of the largest subarray and if no such subarray exist<br>
returns -1.&nbsp;<br>
<br>
<strong>Expected Time Complexity:</strong> O(nlogn)<br>
<strong>Expected Auxiliary Space:</strong> O(1)<br>
<br>
<strong>Constraints:</strong><br>
1&lt;= n&nbsp;&lt;=1000<br>
1&lt;= arr[i] &lt;=1000</span></p>
</div>