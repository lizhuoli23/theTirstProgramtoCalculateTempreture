function [step_m2,over]=Max_round_step(Mx,step,step_max,L)
N=1000;num=1000;phi_eq=0;w=0;over=0;count1=0;

for k=1:num
    M1=Mx(step_max)*(num+1-k)/num;
    M2=Mx(step_max)*(num-k)/num;
    [phi_eq,itg0]=Find(Mx,Mx(step_max),step,step_max);
    [~,itg1]=Find(Mx,M1,step,step_max);
    [~,itg2]=Find(Mx,M2,step,step_max);
    w=w+L/num*(itg0-itg1/2-itg2/2)/(Mx(step_max)/L);
end

if(L/w>=49.9)
    step_m2=phi_eq/step+1;  %·µ»Østep_maxÖµ
    over=1;
else
while(abs(L/w-50)>0.1)
count1=count1+1;
w=0;
for k=1:num
    M1=N*L*(num+1-k)/num;
    M2=N*L*(num-k)/num;
    [phi_eq,itg0]=Find(Mx,N*L,step,step_max);
    [~,itg1]=Find(Mx,M1,step,step_max);
    [~,itg2]=Find(Mx,M2,step,step_max);
    w=w+L/num*(itg0-itg1/2-itg2/2)/N;
end
if(count1<20)
    N=min(N*(1+0.1*(1/50/w*L-1)),Mx(step_max)/L);
elseif(count1<100)
    N=min(N*(1+0.02*(1/50/w*L-1)),Mx(step_max)/L);
else
    N=min(N*(1+0.003*(1/50/w*L-1)),Mx(step_max)/L);
end
step_m2=phi_eq/step+1;
end
end