package com.aman;

import java.util.Random;
import java.util.Scanner;

class game{
    int randno;
    int ui;
    String cn;
    public game(int n ){
            randno = n;
    }
    public int random(){
        return randno;
    }
    public int takeUserInput(){
        return ui;
    }
    public String correctNumber(){
        return cn;
    }
}

public class guess_the_number {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Random rand = new Random();
        int n1 = rand.nextInt(100);
        game g = new game(n1);
        g.ui = sc.nextInt();
        System.out.println(g.ui);
        if(n1==g.ui){
            g.cn = "Correct No.";
            System.out.println(g.cn);
        }
        else{
            g.cn = "No. not correct";
            System.out.println(g.cn);
        }

    }
}
