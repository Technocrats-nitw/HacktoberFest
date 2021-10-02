export default function InsertionSort(array) {
  let temp = [];
  for (let i = 1; i < array.length; ++i) {
    let j = i;
    while (j >= 1 && array[j] < array[j - 1]) {
      temp.push([j, j-1]);
      let t = array[j];
      array[j] = array[j - 1];
      array[j - 1] = t;
      --j;
    }
  }
  return temp;
}
