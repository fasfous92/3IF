function res=creerb2()
    x=1;
    y=zeros(1000,1);
  
    for x=1:11
       y(x,1)=300; 
    end
    for x=1:49
        y(1+20*x,1)=300;
    end
    
    for x=1:50  
      y(20*x,1)=300;
    end
    
    for x=0:10
       y(1000-x,1)=300; 
    end
    
   y(847,1)=500;
   y(848,1)=500; 
   y(849,1)=500;
   y(827,1)=500;
   y(828,1)=500;
   y(829,1)=500;
   y(807,1)=500;
   y(808,1)=500;
   y(809,1)=500;
   
   for x=165:173
       y(x,1)=100;
   end
   for x=185:193
       y(x,1)=100;
   end
   res=y;
    end
       
   
   
   