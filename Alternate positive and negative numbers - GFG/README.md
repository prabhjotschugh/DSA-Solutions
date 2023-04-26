# Alternate positive and negative numbers
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an unsorted array <strong>Arr</strong> of <strong>N</strong> positive and negative numbers. Your task is to create an array of alternate positive and negative numbers without changing the relative order of positive and negative numbers.<br>
<strong>Note: </strong>Array should start with a positive number.</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: 
</strong>N = 9
Arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2}
<strong>Output:</strong>
9 -2 4 -1 5 -5 0 -3 2
<strong>Explanation : </strong>Positive elements : 9,4,5,0,2
Negative elements : -2,-1,-5,-3
As we need to maintain the relative order of
postive elements and negative elements we will pick
each element from the positive and negative and will
store them. If any of the positive and negative numbers
are completed. we will continue with the remaining signed
elements.The output is 9,-2,4,-1,5,-5,0,-3,2.

</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 10
Arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
<strong>Output:</strong>
5 -5 2 -2 4 -8 7 1 8 0
<strong>Explanation : </strong>Positive elements : 5,2,4,7,1,8,0
Negative elements : -5,-2,-8
As we need to maintain the relative order of
postive elements and negative elements we will pick
each element from the positive and negative and will
store them. If any of the positive and negative numbers
are completed. we will continue with the remaining signed
elements.The output is 5,-5,2,-2,4,-8,7,1,8,0.</span></pre>

<p><strong style="font-size:18px">Your Task:&nbsp;&nbsp;</strong></p>

<p><span style="font-size:18px">You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>rearrange()</strong>&nbsp;which takes the array of integers&nbsp;<strong>arr[]</strong><strong>&nbsp;</strong>and<strong>&nbsp;n&nbsp;</strong>as parameters. You need to modify the array itself.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(N)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N&nbsp;≤ 10<sup>7</sup><br>
-10<sup>6</sup> ≤ Arr[i] ≤ 10<sup>7</sup></span></p>
</div>