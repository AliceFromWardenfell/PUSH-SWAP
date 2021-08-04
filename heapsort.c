#include "push_swap.h"

// Функция "просеивания" через кучу - формирование кучи
void	siftDown(int *arr, int root, int bottom)
{
  int max_child; // индекс максимального потомка
  int done = 0; // флаг того, что куча сформирована
  // Пока не дошли до последнего ряда
  while ((root * 2 <= bottom) && (!done)) 
  {
    if (root * 2 == bottom)    // если мы в последнем ряду,
      max_child = root * 2;    // запоминаем левый потомок
    // иначе запоминаем больший потомок из двух
    else if (arr[root * 2] > arr[root * 2 + 1])
      max_child = root * 2;
    else
      max_child = root * 2 + 1;
    // если элемент вершины меньше максимального потомка
    if (arr[root] < arr[max_child]) 
    {
      int temp = arr[root]; // меняем их местами
      arr[root] = arr[max_child];
      arr[max_child] = temp;
      root = max_child;
    }
    else // иначе
      done = 1; // пирамида сформирована
  }
}
// Функция сортировки на куче
void	heap_sort(int *arr, int arr_size)
{
  // Формируем нижний ряд пирамиды
  for (int i = (arr_size / 2); i >= 0; i--)
    siftDown(arr, i, arr_size - 1);
  // Просеиваем через пирамиду остальные элементы
  for (int i = arr_size - 1; i >= 1; i--)
  {
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    siftDown(arr, 0, i - 1);
  }
}
