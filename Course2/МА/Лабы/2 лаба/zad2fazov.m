%������� 2. ������� �������
%y' - y/2x = -1/(2*y)
syms x y Ur Title x_new y_new DU Message;
Ur = '(y^2 - x)/(2*x*y)';
DU = ['Dy = ', char(Ur)]; % ������������ �������. ���������
y = dsolve(DU, 'x'); % ������� ����������������� ���������
y1 = y(1);
y2 = y(2);
fprintf('y = ');
pretty(simplify(y1)); 
pretty(simplify(y2)); 

y1_derivative = diff(y1);
y2_derivative = diff(y2);
fprintf('y'' = ');
pretty(simplify(y1_derivative)); 
pretty(simplify(y2_derivative)); 

grid on; hold on; % �������� ������������ �����
xlabel('��� Y'); % ����������� ��� OX
ylabel('��� Y'''); % ����������� ��� OY
Message1 = ['y=',char(y1)];
Message2 = ['y=',char(y2)];
x_new = 0.1:0.1:10; % ��������� ����� �������� ����������
y1 = subs(y1, x, x_new); % ����������� ��������� 
y2 = subs(y2, x, x_new); % ����������� ��������� 
y1_derivative = subs(y1_derivative, x, x_new); % ����������� ���������
y2_derivative = subs(y2_derivative, x, x_new);
for cycle = 5 : 1: 15
    y1_new = subs(y1, cycle); % ����������� ���������  
    y1_new_derivative = subs(y1_derivative, cycle);
    plot(y1_new, y1_new_derivative, '-black');
    
    y2_new = subs(y2, cycle); % ����������� ���������  
    y2_new_derivative = subs(y2_derivative, cycle);
    plot(y2_new, y2_new_derivative, '-red');
end;
Title = ['������� ������� ���������: ',char(Expr)];
title(char(Title));
legend(char(Message1), char(Message2));
%�����: y = 2*atan(exp(C5 + 2*sin(x)))