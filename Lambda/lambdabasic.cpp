#include <iostream>

int main() {
  int x = 10;
  int y = 20;
  {
    auto capture_by_value = [x, y]() mutable -> int {
      x += 5;
      y += 5;
      std::cout << "Capture by Value Inside lambda: x = " << x << ", y = " << y
                << std::endl;
      return x + y;
    };

    int a = capture_by_value();

    // Print the values of x and y outside the lambda
    std::cout << "Outside lambda: x = " << x << ", y = " << y << std::endl;
    std::cout << a << std::endl;
  }

  {
    // Capture x and y by value and modify them inside the lambda
    auto capture_by_reference = [&x, &y]() -> void {
      x += 5;
      y += 5;
      std::cout << "Capture by Reference Inside lambda: x = " << x
                << ", y = " << y << std::endl;
    };

    // Call the lambda function

    capture_by_reference();

    // Print the values of x and y outside the lambda
    std::cout << "Outside lambda: x = " << x << ", y = " << y << std::endl;
  }

  return 0;
}
