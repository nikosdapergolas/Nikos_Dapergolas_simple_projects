% Sampled Signal Representation with sampling period Ts = 0.001 witch is
% less than the maximum sampling period according to the Nyquist theorem.
% Therefore, signal can be effeciently reconstructed.
Ts = 0.001;
Nmax = t_max / Ts;
n2 = -Nmax:1:Nmax;
% Generate vector storing the samples of the original signal.
xs = cos(100*pi*n2*Ts) + cos(200*pi*n2*Ts) + sin(500*pi*n2*Ts);
% Initialize vector for storing the values of the reconstructed signal.
x2 = zeros(1,length(t));
% Generate the values of the reconstructed signal for each time instance
% within the initial time interval.
for k = 1:1:length(t)
    x2(k) = xs * sinc((t(k)-n2*Ts)/Ts)';
end
% Plot the reconstructed signal along with the original signal.
figure('Name','Reconstructed Signal for Ts = 0.001');
hold on
plot(t,x,'-r','LineWidth',1.5);
plot(t,x2,'*b','LineWidth',1.2);
xlabel('-0.1 \leq t \leq +0.1');
ylabel('x(t) and x2(t)');
grid on