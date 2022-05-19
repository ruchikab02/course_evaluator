ThrowbackPajamas - Shreyansh Jain (sj44), Romina Parimi (rparimi2), Serena Tzeng (stzeng2), Ruchika Biswas (rbiswas4)
CS 225 - Data Structures
12/13/21

## UIUC Prerequisites Final Project - Results Report

Our project culminated in implementations of the Dijkstra's, BFS, and betweenness centrality algorithms for constructing a weighted directed graph for CS/MATH/ENG courses at UIUC based on average GPA. The shortest path between nodes was found by noting the least number of prerequisites required to take a particular course. Edges were weighted based on GPA so students can maximize their GPA while simultaneously taking their course with the least number of prior courses possible. Hence, the UIUC Prerequisites dataset and GPA dataset were filtered and parsed for the course and course numbers, average GPAs, and number of prerequisites for each course.

The shortest path is found as follows:

[BFS](example_outputs/bfs_example1.txt)
[Dijkstra](example_outputs/dijkstra_example1.txt)
[Betweenness Centrality](example_outputs/betweenness_example1.txt)

Final deliverables include the filtering and parsing of the UIUC prerequisite and GPA datasets using Python Pandas, completion of the aforementioned algorithms, construction of the weighted directed graph, and testing of the algorithms and graph. Adjacent nodes and dependencies were checked in testing to ensure the shortest path was found while maximizing GPA to provide the best (i.e. higher GPA and fewer number of prerequisites) possible course options for students. Runtime for each algorithm was as expected as per our proposed implementation strategy: Dijsktra's = O((v+e)log v), BFS = O(v+e), betweenness centrality(O(nm+n^2(log n).
