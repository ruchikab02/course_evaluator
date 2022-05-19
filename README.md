## How to run our code:

1) Open terminal and use git clone to get access to our repository:

2) Navigate to the root directory of our repository


3) Run `make all` in terminal to compile the code for running algorithms or `make bfs`, `make dijkstra`, `make betweenness` for a singular algorithm


4) Choose a dataset to use
  
    Note: it must be formatted exactly like datasets/full_dataset.csv. We reccommend you to use this dataset as it is the most recent data on the University of Illinois` courses prerequisites and courses GPA.


5) To run BFS:
    ```
    ./bin/bfs <filepath to dataset (csv)> <filepath to the output (txt)>
    ```


    Example:


    ```
    ./bin/bfs datasets/full_dataset.csv bfs.txt
    ```


6) To run Dijkstra`s:
    ```
    ./bin/dijkstra <filepath to dataset in a csv file> <filepath to the file to output to>
    ```


    Example:


    ```
    ./bin/dijkstra datasets/full_dataset.csv dijkstra.txt
    ```


7) To run Betweeness Centrality:
    ```
    ./bin/betweenness <filepath to dataset in a csv file> <filepath to the file to output to>
    ```


    Example:


    ```
    ./bin/betweenness datasets/full_dataset.csv betweenness.txt
    ```


8) There are examples of output files for BFS, Dijkstra's, and Betweenness Centrality in the folder `example_outputs`

    *Note: a valid Course must be entered when running our program otherwise the program will terminate.


## How to run tests:

1) Assuming you have already followed steps 1 & 2 from running our program, run `make test_graph_algo` or `make test_graph_imp`


2) Run `./bin/test_graph_imp` to test our graph implementaion and run `./bin/test_graph_algo` to test our graph algorithms


## Repository Structure

Graph/
```
Graph class (which contain our graph algorithms)
Node class
Edge class
```

datasets/
```
Full dataset (to run our program on)
Test dataset (to test with)
Prerequisite dataset (which was used to create full dataset)
GPA dataset (which was used to create full dataset)
Data cleaning python notebook (for preparsing/cleaning our data)
```

example_outputs/
```
Example outputs from our 3 algorithms
```

bin/
```
Executables
```

tests/
```
Catch2 Test Cases
```

## Final Presentation Link
https://youtu.be/W8N_V5axFqM

