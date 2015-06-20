/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package lancope;

import java.util.ArrayList;

/**
 *
 * @author Cong
 */
public class Lancope {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application lo();2 here
        System.out.println("Question 1:\n");
        Node A = new Node();
        Node B = new Node();
        Node C = new Node();
        Node D = new Node();
        A.setName("A");
        A.setSize(2);
        B.setName("B");
        B.setSize(0);
        C.setName("C");
        C.setSize(1);
        D.setName("D");
        D.setSize(0);
        A.setNeighbor(0, B);
        A.setNeighbor(1, C);
        C.setNeighbor(0, D);
        Traverse traverse = new Traverse();
        ArrayList<Node> ret = traverse.walkGraph((A));
        for(int i = 0; i < ret.size(); i++)
            System.out.println("name is " + ret.get(i).getName());
        
        System.out.println("\nQuestion 2:\n");
        ArrayList<ArrayList<Node>> paths = traverse.getpaths(A);
        for(int i = 0; i < paths.size(); i++){
            for(int j = paths.get(i).size() - 1; j >= 0 ; j--){
                System.out.println(paths.get(i).get(j).getName() + " ");
            }
            System.out.println("");
        }
        
        
        
        
    }
    
}
