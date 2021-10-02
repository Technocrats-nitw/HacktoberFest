export default function RadixSort(arr) {
  let changes = [];
  const maxNum = Math.max(...arr) * 10;
  let divisor = 10;
  while (divisor < maxNum) {
    let buckets = [...Array(10)].map(() => []);
    for (let num of arr) {
      buckets[Math.floor((num % divisor) / (divisor / 10))].push(num);
    }
    let i = 0;
    for (let bucket of buckets) {
      for (let element of bucket) {
        changes.push([i, element]);
        ++i;
      }
    }
    arr = [].concat.apply([], buckets);
    divisor *= 10;
  }
  return changes;
}
