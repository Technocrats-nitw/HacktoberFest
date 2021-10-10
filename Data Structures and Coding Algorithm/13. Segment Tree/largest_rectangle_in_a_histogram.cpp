/**
* PROBLEM STATEMENT :

* Given an array of integers heights representing the histogram's bar
* height where the width of each bar is 1, return the area of the
* largest rectangle in the histogram.
*/


/***** SEGMENT TREE APPROACH *****/

// Segment tree node code

class SegTreeNode {
    public:
        int start, end, min;
        SegTreeNode *left;
        SegTreeNode *right;
        SegTreeNode(int start, int end) {
            this->start = start;
            this->end = end;
            left = right = NULL;
        }
};

// Code to build a segment tree

SegTreeNode *buildSegmentTree(vector<int>& heights, int start, int end) {
    if (start > end) return NULL;
    SegTreeNode *root = new SegTreeNode(start, end);

    if (start == end) {
        root->min = start;
        return root;
    } else {
        int middle = (start + end) / 2;

        root->left = buildSegmentTree(heights, start, middle);
        root->right = buildSegmentTree(heights, middle + 1, end);

        root->min = heights[root->left->min] < heights[root->right->min] ? root->left->min : root->right->min;
        return root;
    }
}

// Segment tree query code

int query(SegTreeNode *root, vector<int>& heights, int start, int end) {
    if (root == NULL || end < root->start || start > root->end) return -1;
    if (start <= root->start && end >= root->end) return root->min;

    int leftMin = query(root->left, heights, start, end),
        rightMin = query(root->right, heights, start, end);

    if (leftMin == -1) return rightMin;
    if (rightMin == -1) return leftMin;
    
    return heights[leftMin] < heights[rightMin] ? leftMin : rightMin;
}


int find_area(vector<int>& heights, SegTreeNode* root, int start, int end) {
    if (start > end)
        return -1;

    if (start == end)
        return heights[start];

    int minIndex = query(root, heights, start, end),
        leftMax = find_area(heights, root, start, minIndex - 1),
        rightMax = find_area(heights, root, minIndex + 1, end),
        minMax = heights[minIndex] * (end - start + 1);

    return max(max(leftMax, rightMax), minMax);
}

int largest_rectangle_area_in_histogram(vector<int> heights) {
    int n = heights.size();
    if (n == 0) return 0;

    SegTreeNode *root = buildSegmentTree(heights, 0, n - 1);

    return find_area(heights, root, 0, n - 1);
}

// TIME COMPLEXITY: O(Nlog(N))
// SPACE COMPLEXITY: O(N)