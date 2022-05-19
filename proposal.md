<b>Leading Question</b><br>
We wish to make a general search tool in order to make it easier for students to be able to find courses that are very important in their curriculum for other classes. Our intention is to make a graph visualization that clearly shows course dependencies for the CS, Physics, and Math departments and implement algorithms that would give relevant user data - like which classes would help maximize GPA.<br>

<b>Dataset Acquisition and Processing</b><br>
The data set we plan on using is the [UIUC prerequisites CSV](https://tinyurl.com/2p89mc6j) as well as University of Illinois' [GPA Dataset](https://tinyurl.com/3b3bsmf4) which is also a CSV. We intend to use the data from Spring 2020 for both data sets. We will parse the data by course to get all the nodes and edges based on the prerequisites from the prerequisites CSV. We will then parse the GPA dataset to weight our edges between nodes. We will have to slightly adjust this by changing our weights, because a higher GPA indicates that a course is more difficult. We may choose to accordingly adjust the numbers while preprocessing the data to do a constant minus the average gpa, and then use those as the weights instead, so that it would make sense to use a shortest path algorithm. One method we may try to parse through the data is to use the C++ boost library, since all our data is in the format of a CSV. However, if we come across any problems, we may use Python (probably the pandas library) to preprocess the data.<br>

<b>Graph Algorithms</b><br>
Our group’s plan is to implement Dijkstras’ algorithm, a BFS, as well as a Betweenness Centrality algorithm. We will implement Dijkstras’ algorithm to find the “easiest path” between two nodes. The edges between the nodes of the directed graph will be weighted by GPA, which is being parsed from a separate dataset. Since the directed graph points from a prerequisite to a succeeding class, the Betweenness Centrality algorithm can be used to calculate which classes are the “core” classes for each major (meaning they have the most dependencies). 
For our initial implementation for Dijkstras’ algorithm, we want to try it with an adjacency list and priority queue, which would yield an average runtime of O((v+e) log v), where v is the number of vertices between edges and e is the number of nodes. Our BFS, which will also be implemented with an adjacency list, will have an average runtime of O(v+e), where e is the number of nodes and v is the number of vertices. Our estimated runtime for betweenness centrality is O(ve + v<sup>2</sup> log(v)), where e is the number of nodes and v is the number of vertices.

<b>Timeline</b><br>
November 8th: Finish Final Project Proposal.<br>
November 12th: Environment setup and interface construction.<br>
November 17th: Finish parsing data files.<br>
November 26th: BFS & Dijkstra's algorithm.<br>
December 3rd: Betweenness centrality.<br>
December 10th: Graph construction/visualization.<br>
December 12th: Wrap up and make the final project video and get things ready for submission.<br>
December 13th: Project submission and presentation.<br>


