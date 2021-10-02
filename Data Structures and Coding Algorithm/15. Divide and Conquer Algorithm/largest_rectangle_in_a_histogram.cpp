/**
* PROBLEM STATEMENT :

* Given an array of integers heights representing the histogram's bar
* height where the width of each bar is 1, return the area of the
* largest rectangle in the histogram.
*/


/***** DIVIDE AND CONQUER APPROACH *****/

int find_area(vector<int>& heights, int start, int end) {
    if (start > end)
        return 0;

    int min_index = start;
    for (int i = start; i <= end; i++)
        if (heights[min_index] > heights[i])
            min_index = i;

    return max({heights[min_index] * (end - start + 1),
                find_area(heights, start, min_index - 1),
                find_area(heights, min_index + 1, end)});
}

int largest_rectangle_area_in_histogram(vector<int> heights) {
    return find_area(heights, 0, heights.size() - 1);
}
// TIME COMPLEXITY: 
//                 AVERAGE: O(Nlog(N))
//                 WORST  : O(N^2)
// SPACE COMPLEXITY: O(N)