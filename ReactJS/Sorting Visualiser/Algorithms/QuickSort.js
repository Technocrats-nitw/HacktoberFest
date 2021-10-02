const partition = (array, l, r, res) => {
  let pivot = array[r];
  let i = l - 1;
  for (let j = l; j <= r - 1; ++j) {
    if (array[j] < pivot) {
      ++i;
      res.push([i, j]);
      let t = array[j];
      array[j] = array[i];
      array[i] = t;
    }
  }
  res.push([i+1, r]);
  let t = array[i + 1];
  array[i + 1] = array[r];
  array[r] = t;
  return i + 1;
};

const quickSortUtil = (array, l, r, res) => {
  if (l >= r) return;
  let mid = partition(array, l, r, res);
  quickSortUtil(array, l, mid - 1, res);
  quickSortUtil(array, mid + 1, r, res);
};

export default function QuickSort(array) {
  let res = [];
  quickSortUtil(array, 0, array.length-1, res);
  return res;
}
