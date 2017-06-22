% ������� 2. ��������� ��������.
% y' + y = 3 * exp(-2 * x) * y ^ 2

syms x y Ur Title % ������������� ���������� ����������
syms x_new y_new Expr Message

assume(x, 'real'); % �������� x � y ��������������� �������
assume(y, 'real');

Ur = '3 * exp(-2 * x) * y^2 - y'; % �����. ����. ����� �������.
Expr = ['Dy = ', char(Ur)]; % ������������ �������. ���������

y = dsolve(Expr, 'x'); % ������� ����������������� ���������

y2=y(2);
fprintf('y = ');
Message1 = ['y=', char(y(1))];
Message2 = ['y=', char(y(2))];

pretty(simplify(y)); % ������ ������� ���������

grid on; hold on; % �������� ������������ �����

xlabel('X axis'); % ����������� ��� OX
ylabel('Y axis'); % ����������� ��� OY

x_new = 2:0.1:10; % ��������� ����� �������� ����������
y2 = subs(y2, 'x', x_new); % ����������� ���������

ylim([-0.5 0.5]);
y1=y(1);
for cycle = -2:0.1:2 % ��������� �������� ������. ���������
    val = cycle;
    y_new = subs(y2, val); % ����������� ���������
    plot(x_new, y_new); % ���������� ������������ ������ 
    plot(x_new, y1);
end;

Title = ['Integral Curves of Equation: ', char(Expr)];
title(char(Title)); % ��������� ������� �������
legend(char(Message1), char(Message2)); % ������� �������