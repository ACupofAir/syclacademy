#include <sycl/sycl.hpp>

int main() {
  auto q = sycl::queue{};
  q.submit([&](sycl::handler &cgh) {
     auto os = sycl::stream(1024, 1024, cgh);
     cgh.single_task([=]() { os << "Hello World\n"; });
   }).wait();
  return 0;
}