#ifndef CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN
#endif

#include "../cs225/catch/catch.hpp"
#include "../Graph/Graph.h"
#include "../Graph/Node.h"
#include "../Graph/Edge.h"
#include <iostream>


TEST_CASE("Test Edge Class", "[edge]") {

    Graph graph("datasets/test_dataset.csv");
    std::map<std::string, const Node*> map = graph.getNodes();

    SECTION("Test Edge Constructor") {
        
        REQUIRE(graph.getEdge(map.at("AAS 100"), map.at("AAS 287"))->getOrigin() == map.at("AAS 100"));
        REQUIRE(graph.getEdge(map.at("AAS 100"), map.at("AAS 287"))->getDest() == map.at("AAS 287"));

    }
    SECTION("Test getWeight") {
        REQUIRE(graph.getEdge(map.at("AAS 100"), map.at("AAS 287"))->getWeight() == map.at("AAS 100")->getWeight());
    }
}

TEST_CASE("Test Node Class", "[node]") {

   
    Node node_test("AAS100", 1, 1);
    SECTION("Test Node getName()") {
        REQUIRE(node_test.getName() == "AAS100");
    }
    SECTION("Test Node getWeight()") {
        REQUIRE(node_test.getWeight() == 1);
    }
    SECTION("Test Node getIndex()") {
        REQUIRE(node_test.getIndex() == 1);
    }
    SECTION("Test operator<") {
        REQUIRE(node_test.getWeight() < 1);
    }
}





TEST_CASE("Test Graph Class", "[graph]") {
    Graph graph("datasets/test_dataset.csv");
    std::map<std::string, const Node*> map = graph.getNodes();
    Node node_test("AAS100", 1, 1);
    
    SECTION("Test Graph Constructor") {
        REQUIRE(graph.getNumNodes() == 3);
        REQUIRE(graph.getNumEdges() == 1);
    }
    SECTION("Test pointsTo") {
        REQUIRE(graph.pointsTo(map.at("AAS 100"), map.at("AAS 287")) == true);
        REQUIRE(graph.pointsTo(map.at("AAS 287"), map.at("AAS 100")) == false);
        REQUIRE(graph.pointsTo(map.at("AAS 246"), map.at("AAS 287")) == false);
    }
    
    //above these are ok
    
    SECTION("Test areAdjacent") { 
        const Node* node_test1 = new Node("AAS287",3.0,3); 
        const Node* node_test1; 
        node_test1->setName("AAS287");
        node_test1->setWeight(3.0);
        node_test1->setIndex(3);
        const Node* node_test2 = new Node("AAS100",1.0,1);
        const Node* node_test2;
        node_test2->setName("AAS100");
        node_test2->setWeight(1.0);
        node_test2->setIndex(1);
        REQUIRE(graph.areAdjacent(node_test1,node_test2) == true);
    }
    SECTION("Test insertNode") {
        Node to_insert("AAS370",4,4);
        graph.insertNode(to_insert);
        REQUIRE(graph.getNumNodes() == 4); //initally nodes were 3
    }
    SECTION("Test insertEdge") {
        Node insert_node1("AAS287", 3, 3); 
        // insert_node1->setName("AAS287");
        // insert_node1->setWeight(3.0);
        // insert_node1->setIndex(3);
        
    
        Node insert_node2("AAS100", 1, 1);
        Edge edge(insert_node1,insert_node2);
        graph.insertEdge(insert_node1,insert_node2);
        REQUIRE(graph.getNumEdges() == 5);
    }
   

    
    
    // SECTION("Test insertEdge") {}
    // SECTION("Test tokenize") {}
}

