/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package lancope;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

/**
 *
 * @author Cong
 */
public class Traverse {
    public ArrayList<Node> walkGraph(Node n){
        ArrayList<Node> ret = new ArrayList<>();
        Queue<Node> q = new LinkedList<>();
        q.add(n);
        while(q.peek() != null)
        {
            Node head = q.remove();
            if(!head.visit){
                Node[] children = head.getChildren();
                for(int i = 0; i < head.getSize(); i++){
                    if(!children[i].visit)
                        q.add(children[i]);                        
                }
                head.visit = true;
                ret.add(head);
            }
        }
        return ret;
    }
    
    private void pathHelper(Node node,ArrayList<ArrayList<Node>> paths){
        if(node.getSize() == 0)
        {
            ArrayList<Node> path = new ArrayList<>();
            while(node.getParen() != null){
                path.add(node);
                node = node.getParen();
            }
            path.add(node);
            paths.add(path);
            return;
        }
        for(int i = 0; i < node.getSize(); i++){
           node.getChildren()[i].setParen(node);
           pathHelper(node.getChildren()[i],paths);
        }
    }
    
    public ArrayList<ArrayList<Node>> getpaths(Node node){
        if(node == null)
            return new ArrayList<>();
        else
        {
            ArrayList<ArrayList<Node>> paths = new ArrayList<>();
            pathHelper(node,paths);
            return paths;
        }        
       
    }
    
    
}
