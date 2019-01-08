Use `generate_graph_cpp.py` to regenerate the test: gen_test.h, gen_test.kangaru.h, gen_test.kangaru.2.h, gen_test.manual.hç

The script takes 3 integers as argument:

```python generate_graph_cpp.py <layer> <dependency_count> <shared_dependency>```

- layer: the number of layer of the graph. The first layer always has only one class named "MyClass_0_0"
- dependency_count: How many dependency a generated classes has, except for the last layer which of course does not have any dependency.
- reuse_dependency: How many dependencies are shared with its neighbor.