export default function SelectionSort(array) {
  let i,
    j,
    min_idx,
    n = array.length;
  let swaps = [];
  for (i = 0; i < n - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < n; j++) if (array[j] < array[min_idx]) min_idx = j;
    swaps.push([min_idx, i]);
    let t = array[min_idx];
    array[min_idx] = array[i];
    array[i] = t;
  }
  return swaps;
}
