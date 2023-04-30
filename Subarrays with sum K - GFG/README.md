# Subarrays with sum K
## Medium
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an unsorted array of integers, find the number of continuous subarrays having sum exactly equal to a given number k.</span></p>

<p><br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 5
Arr = {10 , 2, -2, -20, 10}
k = -10
<strong>Output:</strong> 3
<strong>Explaination:</strong> 
Subarrays: arr[0...3], arr[1...4], arr[3..4]
have sum exactly equal to -10.</span></pre>

<p><br>
<span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 6
Arr = {9, 4, 20, 3, 10, 5}
k = 33
<strong>Output:</strong> 2
<strong>Explaination:</strong> 
Subarrays : arr[0...2], arr[2...4] have sum
exactly equal to 33.</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>findSubArraySum()</strong>&nbsp;which takes the array <strong>Arr[]</strong> and its size <strong>N </strong>and <strong>k&nbsp;</strong>as input parameters&nbsp;and returns the count of subarrays.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(NlogN</span><span style="font-size:18px">)</span><br>
<span style="font-size:18px"><strong>Expected Auxiliary Space:</strong> O(N)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 2*10<sup>4</sup><br>
-10<sup>3</sup> ≤ Arr[i]&nbsp;≤ 10<sup>3</sup><br>
-10<sup>7</sup>&nbsp;≤ k&nbsp;≤ 10<sup>7</sup></span></p>
</div>