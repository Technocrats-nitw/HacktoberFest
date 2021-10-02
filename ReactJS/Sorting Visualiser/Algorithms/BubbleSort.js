export default function BubbleSort(array) {
  let swaps = [];
  let i, j;
  let swapped;
  let n = array.length;
  for (i = 0; i < n - 1; i++) {
    swapped = false;
    for (j = 0; j < n - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        swaps.push([j, j + 1]);
        let t = array[j];
        array[j] = array[j+1];
        array[j+1] = t;
        swapped = true;
      }
    }
    if (swapped === false) break;
  }
  return swaps;
}
