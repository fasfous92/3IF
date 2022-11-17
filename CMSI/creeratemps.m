function res=creeratemps()
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
    
    for x=11:20
        y(x,x+970)=1; 
        y(x+970,x)=1;
    end
    
     
    y(1,1)=-2;
    y(20,20)=-2;
    y(1000,1000)=-2;
    y(980,980)=-2;
    
    for x=2:19
        y(x,x)=-3;
    end
    
    for x=981:999
        y(x,x)=-3;
    end
    
    
    for x=1:48
        y(1+20*x,1+20*x)=-3;
    end
    for x=2:49
        y(20*x,20*x)=-3;
    end
    for x=11:20
        y(x,x)=-4; 
        y(x+970,x+970)=-4;
    end
    y(981,981)=-3;
    y(20,20)=-3;
    res=y;


end