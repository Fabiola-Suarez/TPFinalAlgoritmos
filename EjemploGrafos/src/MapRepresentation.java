public class MapRepresentation {
 
    public static Graph getCities() 
    {
        Node ba = new Node("BsAs");
        Node mdp = new Node("Mar del Plata");
        Node usu = new Node("Ushuaia");
        Node juy = new Node("Jujuy");
        Node cor = new Node("Cordoba");
 
        ba.addEdge(new Edge(ba, mdp, 100));
        ba.addEdge(new Edge(ba, usu, 900));
 
        mdp.addEdge(new Edge(mdp, juy, 150));
        mdp.addEdge(new Edge(mdp, cor, 350));
        mdp.addEdge(new Edge(mdp, usu, 340));
 
        usu.addEdge(new Edge(usu, cor, 100));
 
        cor.addEdge(new Edge(cor, juy, 20));
 
        Graph graph = new Graph();
        graph.addNode(ba);
        graph.addNode(mdp);
        graph.addNode(usu);
        graph.addNode(cor);
        return graph;
    }
 
    public static void main(String[] args) 
    {
        Graph graph = getCities();
        System.out.println(graph);
    }
}