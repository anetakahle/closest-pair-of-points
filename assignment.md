The input will contain a set of points in the plane. Your goal is to find and write out the closest pair of points.

### Input format
The first line of standard input will contain a number N indicating the number of points. N rows will follow, each giving the coordinates of a single point (as two integers separated by a space).

Point coordinates are in the range -2^30 to +2^30, so the square of the distance between any two points will fit into a 64-bit integer (long long). N will be at most 200,000. We promise nothing else about the points (e.g. they will not necessarily be in general linear position.)

### Output format
Write three space-separated integers to standard output: the square of the distance between the two closest points (so we can avoid floating-point computations) and the indices of these two points in the input order. Points are indexed from zero and you must write the lower index first. The solution will be unique (there will be only one pair of minimal distance).

### Sample input
```
5
0 0
0 10
3 3
10 0
10 10
```
### Sample output
```
18 0 2
```
The square of the distance is (3-0)^2 + (3-0)^2 = 9 + 9 = 18.
