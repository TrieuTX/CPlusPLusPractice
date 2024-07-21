#include <functional>
#include <iostream>
class Test {
public:
  int x = 2;
  void test1(void) { std::cout << "test1" << std::endl; };

  void test_lambda(void) {
    auto lambda = [&]() {
      std::cout << "x: " << x << " y: " << y << " z: " << z << std::endl;
      this->test1();
    };
    lambda();
  }

  void test_lambda(Test &test) {
    auto lambda = [this, &test]() {
      test.x++;
      this->x++;
      std::cout << "test.x: " << test.x << " this->x: " << x << std::endl;
    };
    lambda();
  }

  void apply(int &scale, std::function<int(int)> f) {
    std::cout << "std::funtion: " << f(scale) << std::endl;
  }

  void swap(int &a, int &b, std::function<bool(int, int)> f) {
    if (f(a, b)) {
      int temp = a;
      a = b;
      b = temp;
    }
  }

  void bubbleSort(std::vector<int>::iterator begin,
                  std::vector<int>::iterator end,
                  std::function<bool(int, int)> compFunction) {
    for (std::vector<int>::iterator i = begin; i != end; ++i) {
      for (std::vector<int>::iterator j = begin; j != end - (i - begin) - 1;
           ++j) {
        if (compFunction(*(j + 1), *j)) {
          // std::swap(*j, *(j + 1));
          int temp = *(j + 1);
          *(j + 1) = *j;
          *j = temp;
        }
      }
    }
  }

protected:
  int y = 3;

private:
  int z = 4;
};

int main() {
  Test test;
  test.test_lambda();
  Test test2;
  test.test_lambda(test2);
  std::cout << "test2.x: " << test2.x << " test.x: " << test.x << std::endl;
  int c = 2;
  int scale = 4;
  test.apply(scale, [c](int a) -> int { return a += c; });
  int a = 1;
  int b = 2;
  test.swap(a, b, [](int x, int y) -> bool { return x > y; });
  std::cout << "a: " << a << " b: " << b << std::endl;

  std::vector<int> vec{1, 3, 9, 8, 0};
  test.bubbleSort(vec.begin(), vec.end(),
                  [](int a, int b) -> bool { return a > b; });
  std::cout << "Sorted vector: ";
  for (int num : vec) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
  return 0;
}
