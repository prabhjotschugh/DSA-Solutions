# Max distance between same elements
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:20px">Given an array with repeated elements, the task is to find the maximum distance between two occurrences of an element.</span></p>

<p><span style="font-size:20px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:20px"><strong>Input</strong></span><span style="font-size:20px">
n= 6
arr = {1, 1, 2, 2, 2, 1}</span>

<span style="font-size:20px"><strong>Output</strong>
5</span>

<span style="font-size:20px"><strong>Explanation</strong>
arr[] = {1, 1, 2, 2, 2, 1}
Max Distance: 5
Distance for 1 is: 5-0 = 5
Distance for 2 is : 4-2 = 2
Max Distance 5</span></pre>

<p><span style="font-size:20px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:20px"><strong>Input</strong>
n = 12
arr = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2}</span>

<span style="font-size:20px"><strong>Output</strong>
10</span>

<span style="font-size:20px"><strong>Explanation</strong></span>



<span style="font-size:20px">arr[] = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2}
Max Distance 10
maximum distance for 2 is 11-1 = 10
maximum distance for 1 is 4-2 = 2
maximum distance for 4 is 10-5 = 5</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
Complete <strong>maxDistance() </strong>function which takes both the given array and their size as function arguments and returns the maximum distance between 2 same elements. </span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity </strong>: O(N)<br>
<strong>Expected Auxilliary Space</strong> : O(N)</span></p>

<p><span style="font-size:20px"><strong>Constraints:</strong></span></p>

<p><span style="font-size:20px">1&lt;=N&lt;=10<sup>6</sup></span></p>

<p>&nbsp;</p>

<p>&nbsp;</p>
</div>