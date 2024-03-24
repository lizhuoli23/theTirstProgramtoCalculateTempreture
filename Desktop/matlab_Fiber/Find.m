function [phi,itg]=Find(Mx,M,step,step_max)
ceil=1;itg=0;


for k=2:step_max
    if(Mx(k)>=M && ceil==1)
        ceil=k;
    end
    if(Mx(step_max)<M)
        ceil=1;
    end
    if(ceil==1 && k>1)
        itg=itg+(Mx(k)-Mx(k-1))*(k-0.5)*step;
    end
end
if(Mx(step_max)<M)
    phi=(step_max-1)*step;
else
    phi=step*(ceil-1-(Mx(ceil)-M)/(Mx(ceil)-Mx(ceil-1)));
    itg=itg+(M-Mx(ceil-1))*0.5*(phi/step+ceil)*step;
end
end