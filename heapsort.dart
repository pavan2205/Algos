import 'heap.dart';

List<E> heapsort<E extends Comparable<dynamic>>(List<E> list) {
  // 1
  final heap = Heap<E>(
    elements: list.toList(),
    priority: Priority.min,
  );
  // 2
  final sorted = <E>[];
  // 3
  while (!heap.isEmpty) {
    final value = heap.remove();
    sorted.add(value!);
  }
  return sorted;
}
