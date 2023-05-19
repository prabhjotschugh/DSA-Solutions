# Missing element of AP
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Find the missing element from an ordered array <strong>arr[]</strong>, consisting of <strong>N</strong> elements representing an Arithmetic Progression(AP).</span></p>

<p><span style="font-size:18px"><strong>Note:&nbsp;</strong>There always exists an element which upon inserting into sequence forms Arithmetic progression. Boundary elements (first and last elements) are not missing.</span><br>
<br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 6
Arr[] = {2, 4, 8, 10, 12, 14}
<strong>Output:</strong> 6
<strong>Explanation:</strong> Actual AP should be 
2, 4, <strong>6</strong>, 8, 10, 12, 14.
</span></pre>

<p><br>
<span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 6
Arr[] = {1, 6, 11, 16, 21, 31}
<strong>Output:</strong> 26
<strong>Explanation:</strong>&nbsp;Actual AP should be 
1, 6, 11, 16, 21, <strong>26</strong>, 31.</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>findMissing()</strong>&nbsp;which takes the array of integers&nbsp;<strong>arr[]&nbsp;</strong>and its size&nbsp;<strong>n&nbsp;</strong>as input parameters and returns an integer denoting the answer.</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(logN)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
2 &lt;= N<strong> </strong>&lt;= 10<sup>5</sup><br>
0 &lt;=<strong>&nbsp;</strong>|Arr[i]| &lt;= 10<sup>7</sup></span><br>
<span style="font-size:18px">There will always be only one missing element.</span></p>
</div>