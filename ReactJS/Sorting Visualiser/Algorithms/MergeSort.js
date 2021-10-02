function merge(arr, l, m, r, res) {
  let n1 = m - l + 1;
  let n2 = r - m;
  let L = new Array(n1);
  let R = new Array(n2);
  for (let i = 0; i < n1; i++) L[i] = arr[l + i];
  for (let j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
  let i = 0;
  let j = 0;
  let k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    res.push([k, arr[k]]);
    k++;
  }
  while (i < n1) {
    arr[k] = L[i];
    i++;
    res.push([k, arr[k]]);
    k++;
  }
  while (j < n2) {
    arr[k] = R[j];
    j++;
    res.push([k, arr[k]]);
    k++;
  }
}

function MergeSortUtil(arr, l, r, res) {
  if (l >= r) {
    return;
  }
  let m = l + parseInt((r - l) / 2);
  MergeSortUtil(arr, l, m, res);
  MergeSortUtil(arr, m + 1, r, res);
  merge(arr, l, m, r, res);
}

export default function MergeSort (array, l, r) {
  let res = [];
  MergeSortUtil(array, 0, array.length-1, res);
  return res;
}
