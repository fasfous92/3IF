function res=creera2()
    y=zeros(1000,1000);
    
    for x=1:1000
      %if any(x~=1:11) && any(x~=21:20:1000) && any(x~=20:20:1000) && any(x~=990:1000) && any(x~=847:849) && any(x~=827:829) && any(x~=807:809) && any(x~=165:173) && any(x~=185:193)
           y(x,x)=-4;
           if x-1>=1
               y(x,x-1)=1;
           end
           if x+1<=1000
               y(x,x+1)=1;
           end
           if x-20>=1
               y(x,x-20)=1;
           end
           if x+20<=1000
               y(x,x+20)=1;
           end
           
       %end
       
    end
   
    
    
    for x=12:19
        y(x,x+970)=1; 
        y(x+970,x)=1;
    end
    
    
    for x=1:11
       y(x,1:1000)=0;
       y(x,x)=1; 
    end
    
    for x=1:49
        y(1+20*x,1:1000)=0;
        y(1+20*x,1+20*x)=1;
        y(1+20*x,1+20*x-1)=0;
        y(1+20*x,1+20*x+1)=0;
        y(1+20*x,1+20*x-20)=0;
        %y(1+20*x,1+20*x+20)=0;
        
    end
    
    for x=1:50  
      y(20*x,1:1000)=0;
      y(20*x,20*x)=1;
    end
    
    for x=0:10
       y(1000-x,1:1000)=0;
       y(1000-x,1000-x)=1; 
    end
    
   y(847:849,1:1000)=0;
   y(847,847)=1;
   y(848,848)=1; 
   y(849,849)=1;
   y(827:829,1:1000)=0;
   y(827,827)=1;
   y(828,828)=1;
   y(829,829)=1;
   y(807:809,1:1000)=0;
   y(807,807)=1;
   y(808,808)=1;
   y(809,809)=1;
   
   for x=165:173
       y(x,1:1000)=0;
       y(x,x)=1;
   end
   for x=185:193
       y(x,1:1000)=0;
       y(x,x)=1;
   end 
    res=y;

end
