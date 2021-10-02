/**
* PROBLEM STATEMENT :

* Given an array of integers heights representing the histogram's bar
* height where the width of each bar is 1, return the area of the
* largest rectangle in the histogram.
*/


/***** BRUTE FORCE APPROACH *****/

int largest_rectangle_area_in_histogram(vector<int> heights) {
    int max_area = 0;

    for (int i = 0; i < heights.size(); i++) {

        for (int j = i; j < heights.size(); j++) {
            int min_height = INT_MAX;

            for (int k = i; k <= j; k++)
                min_height = min(min_height, heights[k]);

            max_area = max(max_area, min_height * (j - i + 1));
        }
    }
    return max_area;
}
// TIME COMPLEXITY: O(N^3)
// SPACE COMPLEXITY: O(1)



/***** BRUTE FORCE APPROACH OPTIMIZED THAN ABOVE *****/

int largest_rectangle_area_in_histogram(vector<int> heights) {
    int max_area = 0;

    for (int i = 0; i < heights.size(); i++) {
        int min_height = INT_MAX;

        for (int j = i; j < heights.size(); j++) {
            min_height = min(min_height, heights[j]);
            max_area = max(max_area, min_height * (j - i + 1));
        }
    }
    return max_area;
}
// TIME COMPLEXITY: O(N^2)
// SPACE COMPLEXITY: O(1)



/***** STACK APPROACH *****/

int largest_rectangle_area_in_histogram(vector<int> heights) {
        stack<int> s;
        s.push(-1);
        int max_area = 0;

        for (int i = 0; i < heights.size(); i++) {

            while (s.top() != -1 and heights[s.top()] >= heights[i]) {
                int current_height = heights[s.top()];
                s.pop();
                int current_width = i - s.top() - 1;
                max_area = max(max_area, current_height * current_width);
            }

            s.push(i);
        }

        while (s.top() != -1) {
            int current_height = heights[s.top()];
            s.pop();
            int current_width = heights.size() - s.top() - 1;
            max_area = max(max_area, current_height * current_width);
        }
        return max_area;
    }
// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(N)