/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package lancope;

/**
 *
 * @author Cong
 */
public class Node implements GNode {
    public boolean visit;
    private Node paren;
    private String name;
    private int size;
    private Node[] neighbor;
    
    
    public Node(){
        name = "";
        visit = false;
        size = 0;
        neighbor = null;
        paren = null;
    }
    
    public void setParen(Node paren){
        this.paren = paren;
    }
    
    public Node getParen()
    {
        return this.paren;
    }
    
    public void setSize(int n){
        this.neighbor = new Node[n];
        this.size = n;
    }
    
    public void setName(String name)
    {
        this.name = name;
    }
    
    public void setNeighbor(int i, Node n){
        this.neighbor[i] = n;
    }
    
     @Override
     public String getName(){
         return this.name;
     }
     
     public int getSize(){
         return this.size;
     }
     
     @Override
     public Node[] getChildren(){
         return this.neighbor;
     }
     
}
