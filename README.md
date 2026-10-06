*This project has been created as part of the 42 curriculum by mradkovi, hpiotrow.*

# push_swap
![push_swap](https://github.com/martinaradkovicova-lgtm/ft_push_swap/blob/main/diagrams_png/Gemini_Generated_Image_xs679cxs679cxs67.jpeg?raw=true)
## Description

`push_swap` is an algorithmic project whose goal is to **sort a stack of
unique integers using the smallest possible number of operations**, given
only two stacks (`a` and `b`) and a restricted set of moves to manipulate
them.

The program receives a list of integers as command-line arguments,
pushes them onto stack `a`, and must print to standard output the
shortest reasonable sequence of operations (`sa`, `sb`, `ss`, `pa`, `pb`,
`ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`) that results in stack `a` being
sorted in ascending order with stack `b` empty.

Beyond basic correctness, this version of the project requires
implementing and comparing **four distinct sorting strategies**,
selectable at runtime, each targeting a different complexity class
measured in *number of operations generated* rather than classical
array-based time complexity:

- a simple **O(n²)** strategy,
- a medium **O(n√n)** strategy,
- a complex **O(n log n)** strategy,
- and an **adaptive** strategy that picks one of the above at runtime
  based on a measured *disorder* score of the input.

## Operations
 
| Operation | Description |
|---|---|
| `sa` | Swap the first two elements at the top of stack `a`. Does nothing with one or no elements. |
| `sb` | Swap the first two elements at the top of stack `b`. Does nothing with one or no elements. |
| `ss` | Equivalent to `sa` and `sb` at the same time. |
| `pa` | Take the top element of `b` and push it onto the top of `a`. Does nothing if `b` is empty. |
| `pb` | Take the top element of `a` and push it onto the top of `b`. Does nothing if `a` is empty. |
| `ra` | Rotate `a` up by one: the first element becomes the last. |
| `rb` | Rotate `b` up by one: the first element becomes the last. |
| `rr` | Equivalent to `ra` and `rb` at the same time. |
| `rra` | Reverse-rotate `a` down by one: the last element becomes the first. |
| `rrb` | Reverse-rotate `b` down by one: the last element becomes the first. |
| `rrr` | Equivalent to `rra` and `rrb` at the same time. |
 
## Instructions

### Compilation

```sh
make        # builds the push_swap binary
make clean  # removes object files
make fclean # removes object files and the binary
make re     # fclean + all
```

The Makefile tracks header dependencies automatically and never
relinks unnecessarily.

### Usage

```sh
./push_swap [--simple | --medium | --complex | --adaptive] [--bench] n1 n2 n3 ...
```

- The integers are space-separated, must be unique, and must fit in a
  signed 32-bit integer range.
- The strategy flag is optional; `--adaptive` is used by default if
  none is given.
- `--bench` can be combined with any strategy flag (or used alone,
  defaulting to adaptive) to print, to **stderr**, the measured
  disorder, the strategy actually used with its complexity class, the
  total operation count, and a per-operation breakdown. Standard
  output always contains only the operation sequence, one per line.
- With no arguments at all, the program prints nothing and returns
  control to the prompt.
- On invalid input (non-integer arguments, out-of-range integers,
  duplicate values, or an unrecognized flag), the program prints
  `Error` followed by a newline to stderr.

### Examples
**Force the simple (O(nˆ2)) strategy:**
```sh
./push_swap --simple 5 4 3 2 1
rra
pb
rra
pb
sa
rra
pa
pa
```
**Default selection (--adaptive) and operation count:**
```sh
ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG | wc -l
9
```

**Checking correctness**

A separate `checker` program (provided by the campus, not part of
this repository) can replay a sequence of operations against the
same starting input to verify the result:

```sh
ARG="3 1 2 5 4"
./push_swap $ARG | ./checker $ARG
```

**Run with benchmark enabled; hide operations and show only metrics:**
```sh
shuf -i 0-9999 -n 500 > args.txt ; ./push_swap --bench $(cat args.txt) 2> bench.txt | ./checker_linux $(cat args.txt)
OK
cat bench.txt
[bench]  Disorder: 49.11%
[bench]  Strategy: adaptive (O(n√n))
[bench]  Total ops: 7394
[bench]  sa: 0
[bench]  sb: 0
[bench]  ss: 0
[bench]  ra: 2802
[bench]  rb: 1832
[bench]  rr: 0
[bench]  rra: 0
[bench]  rrb: 1760
[bench]  rrr: 0
[bench]  pa: 500
[bench]  pb: 500
```
**Error management examples:**
```sh
./push_swap --adaptive 0 one 2 3
Error
```
```sh
./push_swap --simple 3 2 3
Error
```


## Algorithms

### Disorder metric

Before any move is made, disorder is computed as the fraction of
out-of-order pairs in stack `a`:

```
disorder = mistakes / total_pairs
```

where a mistake is any pair `(i, j)`, `i` above `j` in the stack,
with `value(i) > value(j)`, and `total_pairs = n·(n-1)/2`. Disorder is
`0` for an already sorted stack and approaches `1` for a fully
reverse-sorted one. This computation is O(n²) in time but emits no
push_swap operations, so it does not count toward the operation-based
complexity of any strategy.

### Simple — O(n²)

Stacks of size 0–2 are resolved directly (at most one `sa`). 
Sizes 3, 4, and 5 use hardcoded decision trees (`sort_three`, `sort_four`,
`sort_five`) that peel off the global minimum and recurse into the
next-smaller hardcoded case, each resolving in a small, fixed number
of operations.

For larger stacks, a **greedy cost-based insertion
sort** is used: for every remaining element of `a`, the algorithm
computes the true cheapest way to insert it into `b` — combining the
rotation cost on `a` (to bring that element to the top) with the
rotation cost on `b` (to reach its correct sorted position) — and
moves the globally cheapest element each iteration, using combined
`rr`/`rrr` rotations whenever both stacks need to rotate in the same
direction. Each insertion costs O(n) to evaluate (scanning both
stacks), and n insertions are performed, giving **O(n²) operations**
in the worst case, O(1) extra space beyond the stacks themselves.

This is a deliberate upgrade over a plain selection sort: picking the
*globally* cheapest move each step, rather than always extracting the
current minimum, measurably reduces the real operation count while
remaining in the same O(n²) class.


![sort_three_alg](https://github.com/martinaradkovicova-lgtm/ft_push_swap/blob/main/diagrams_png/sort_3.png?raw=true)
![sort_four_alg](https://github.com/martinaradkovicova-lgtm/ft_push_swap/blob/main/diagrams_png/sort4.png?raw=true)
![sort_five_alg](https://github.com/martinaradkovicova-lgtm/ft_push_swap/blob/main/diagrams_png/sort_5.png?raw=true)

### Medium — O(n√n)

After assigning every element a rank (0 to n-1, via a temporary sorted
copy of the stack's values — this removes any dependency on the
actual magnitude or sign of the input values), the rank range is
split into `~√n` chunks. For each chunk, one full O(n) sweep of `a`
routes that chunk's elements into `b` (`pb`) while rotating
(`ra`) everything else out of the way. After all chunks have been
distributed, `b` is drained back into `a` by repeatedly rotating the
current maximum to the top of `b` and pushing it across — since each
extracted element is smaller than the one before it, `a` rebuilds in
ascending order.

**Complexity argument:** `√n` chunk-sweeps, each costing O(n), gives
O(n√n) for the distribution phase; the chunk count scaling with `√n`
(rather than a fixed constant) is exactly what keeps this in the
O(n√n) class rather than degrading toward O(n²). Space is O(n) for
rank bookkeeping.

![medium_alg1](https://github.com/martinaradkovicova-lgtm/ft_push_swap/blob/main/diagrams_png/medium_alg1.png?raw=true)
![medium_alg2](https://github.com/martinaradkovicova-lgtm/ft_push_swap/blob/main/diagrams_png/medium_alg2.png?raw=true)


### Complex — O(n log n)

Using the same rank assignment as medium, this strategy applies an
**LSD (Least Significant Digit) radix sort in base 2**. For each bit
position, from the least to the most significant bit of the largest
rank, one full sweep routes every element whose current bit is `1`
into `b` (`ra` otherwise), then `b` is drained back into `a`. Because
`pb`/`pa` preserve relative order (the moves are *stable*), each pass
refines the ordering by exactly one more binary digit without
disturbing what previous passes already established; after
`⌈log₂n⌉` passes the stack is fully sorted, with no recursion
required.

**Complexity argument:** `⌈log₂n⌉` passes, each an O(n) sweep plus an
O(n) drain, gives **O(n log n) operations**. Space is O(n) for rank
bookkeeping, same as medium.

![complex_alg_binary](https://github.com/martinaradkovicova-lgtm/ft_push_swap/blob/main/diagrams_png/complex_alg_binary.png?raw=true)
![complex_alg](https://github.com/martinaradkovicova-lgtm/ft_push_swap/blob/main/diagrams_png/complex_alg.png?raw=true)

### Adaptive

Dispatches to one of the three strategies above based on the measured
disorder, per the required thresholds:

| Disorder | Strategy used | Complexity |
|---|---|---|
| `< 0.2` | simple | O(n²) |
| `0.2 – 0.5` | medium | O(n√n) |
| `≥ 0.5` | complex | O(n log n) |

**Rationale for these thresholds:** at low disorder, the number of
actual inversions is small, so even an O(n²)-class algorithm performs
very little real work — our cost-based insertion sort in particular
degrades gracefully, since most elements are already close to their
correct position and each insertion's cost search converges quickly.
As disorder grows, the number of misplaced elements grows with it,
and a flat insertion-sort approach starts generating meaningfully more
operations than a chunked distribution would; the `0.2` crossover
matches the thresholds specified by the subject and was validated
empirically against measured operation counts across the regime
boundary. Above `0.5` disorder, most pairs are inverted and the
radix-based approach's fixed `log n` pass count keeps the operation
count bounded in a way neither of the other two strategies can match
at that level of disorder.

Stacks of 5 or fewer elements always use the simple strategy under
adaptive, regardless of measured disorder, since the hardcoded small
cases are unconditionally cheaper than routing through medium or
complex's setup overhead at that size.

### Measured performance

Benchmarked with random inputs via the project's required targets:

| n | Strategy | Approx. ops | Target tier |
|---|---|---|---|
| 100 | simple | ~1,400 | Good |
| 100 | medium / adaptive | ~800 | Good |
| 100 | complex | ~1,100 | Good |
| 500 | medium / adaptive | ~8,200 | Good |
| 500 | complex | ~6,800 | Good |

Numbers vary by input and are provided as a representative snapshot,
not a guarantee; see the `--bench` flag to measure any given run
directly.

## Contributions

This project was built by two learners. Contributions are split as
follows:

**mradkovi** — project foundation and infrastructure:
- Stack data structure (`t_num`/`t_stack`, doubly linked list) and
  all 11 push_swap operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`,
  `rb`, `rr`, `rra`, `rrb`, `rrr`).
- Argument parsing and validation (duplicate detection, integer
  range checking, flag parsing, multi-flag support for `--bench`).
- The disorder metric (`compute_disorder`).
- `main`/`run_push_swap` control flow and memory management.
- Simple strategy: hardcoded `sort_three`/`sort_four`/`sort_five`
  and the cost-based greedy insertion sort for larger stacks.

**hpiotrow** — sorting algorithms and bench mode:
- Medium strategy: rank assignment (`pre_sort`), chunk-based
  distribution, and the max-extraction drain.
- Complex strategy: LSD radix sort (bit-based distribution and
  drain over `⌈log₂n⌉` passes).
- Adaptive strategy: threshold-based dispatch between the three
  above.
- `--bench` mode: operation counting, stderr reporting of disorder,
  strategy, complexity class, and per-operation breakdown.

Both learners reviewed and tested each other's code; debugging and
threshold tuning (see **Algorithms**, above) were done jointly.

## Resources

- *push_swap* subject PDF (42 Network / École 42 internal
  documentation).
- ALGORITHMS IN A NUTSHELL A Desktop Quick Reference - O`REILLY George T. Heineman, Gary Pollice & Stanley Selkow
- Mastering Algorithms with C - O`REILLY Kyle Loudon
- Grokking algorithms - An illustrated guide for programmers and other curious people - Aditya Y. Bhargava
- Pointers in C Programming - A Modern Approach to Memory Management, Recursive Dava Structures, Strings, and Arrays - Thomas Mailund

### AI usage
 
In line with the school's AI-usage guidelines, AI (Claude, Anthropic)
was used as a support tool for specific, bounded tasks — never to
generate unreviewed code dropped directly into the project. Every
use below was followed by manual review, hand-tracing, or testing
before anything was kept, and debugging in particular was done
jointly by both learners rather than taken on AI's word alone.
 
- **Planning** — generating project roadmap diagram, as well as a
  checklist for each part of the project.
- **Concept explanations, on request** — disorder metrics, Big-O
  notation in the operation-count model specific to this project
  (as opposed to classical array complexity), doubly linked lists,
  LSD radix sort, and bitwise operations. Used to build
  understanding before implementing, not as a substitute for it.
- **Code review of our own hand-written C** — flagging specific
  issues which we then traced through by hand, confirmed, and fixed
  ourselves. AI explanations of *why* something was wrong were checked
  against the actual code and, where uncertain, discussed between us
  before being accepted.
- **Drafting aid** — explanatory code comments and this README's
  prose, written after the underlying logic was already understood
  and finalized by us.
Every algorithm's logic, every fix, and every line of final code was
written, tested, and can be explained by both of us — that was our
bar for accepting anything AI suggested, rather than compiling
successfully or "looking right." Debugging sessions and the
adaptive-threshold decisions in particular were worked through
together as peers, using AI output as one input among several, not
as the final word.
