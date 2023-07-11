import dis
from time import perf_counter
from perfcounters import PerfCounters

def foo(numbers):
    for i, num in enumerate(numbers):
        res = i + num

def boo(numbers):
    for i in range(len(numbers)):
        res = i + numbers[i]

dis.dis(foo)
print()
dis.dis(boo)
numbers = [n for n in range(10_000_000)]

start = perf_counter()
foo(numbers)
print(f'{(perf_counter() - start):.3f}')

start = perf_counter()
boo(numbers)
# for i in range(len(numbers)):
#     res = i + numbers[i]
print(f'{(perf_counter() - start):.3f}')

counter = PerfCounters()
counter.start('random loop')
foo(numbers)
# for i in range(len(numbers)):
#     res = i + numbers[i]
#     #counter.lap('random loop')
counter.stop('random loop')
counter.report()