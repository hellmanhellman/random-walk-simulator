# random-walk-simulator


A random walker written in C using SDL2 and compiled on macOS Big Sur 11.5.
Simulates 200 million coin tosses (epochs) in about 4 seconds, then plots how the score changed over time. This is a great way to get intuition about the very interestingly applicable $1 dollar wager game: 

# For developers
This code is very basic and can be easily adaptabe to run any other fast physics simulation that you might need.


# Installation
If you're interested feel free to clone the repo, and -- first look through the source file and see that it's not maliscious, then compile it yourself, using the command specified below. 

You will need to have the [SDL2 library](https://www.libsdl.org) installed for the plotter to work. I'm using macOS I got it working after a couple of hours. Try with `brew install sdl2`, try it through xcode, try it (this worked for me) using the [SDL2 library](https://www.libsdl.org) resources.

Once your compiler recognizes SDL2 you can compile this program. If you're on mac, you just clone the repo, cd inside it, and then in the terminal type the commands 


```
cc -o main.o $(sdl2-config --cflags --libs) random-walk-simulator.c
./main.o
```

# Unintuitive physics
Two persons A and B flip a coin and if it's heads, A gives $1 to B. If it's tails, B instead gives $1 to A.
If they keep playing, how do you expect the score will change over time?
Will it often reach 0 and cross over into the others favor, or will that happen only rarely?
In the course of playing, how many percent of the time was the score positive? You might expect the answer to be is "around 50%". But though it does always tend to 50%, it only does that when you are running a serious aomount of friendly coin wagers. Only at 200 million coin tosses does the score usually tend to balance. 

it is in reality much more common to have the score be in favor of one side for more than 95% of the game, even if youre playing 10 million games.
So what? Well I like to think about it as a model for testing scientific hypothesis. Testing some idea you have scientifically means that you 
formulate your conjecture, a null hypothesis which holds that the effects your original theory is trying to correlate, could also have gotten their "relationships" completely randomly.

An example paraphrased from William Fellers Introduction to Probability Theory and Its Applications:

Image that you were a teacher, and you were grading students throughout a year, and was nearing the time for summarizing scores and setting their grades.
If you had one child who was behind on his studies for 11 months our of the year, then caught up -- and one other kid who instead was in the lead for the first 9 months, but had since then been slowly slipping. Which one of them needs your help? The answer is almost certainly none of them. These seemingly outlying results would reappear if made your tests random. These huge segregations will still appear regularly. 


# Examples 

Running 200 000 000 epochs, you can see the law of large numbers starting to creep in.

<img width="441" alt="plot-example" src="https://user-images.githubusercontent.com/9209644/126708655-a8278967-8a2b-4d48-aa96-635f67563473.png">

<img width="990" alt="console-example" src="https://user-images.githubusercontent.com/9209644/126706670-a410d3a5-c3c4-4948-807e-2fdaaa329c5b.png">

#Another example, using 10 million epochs:

<img width="1729" alt="Screenshot 2021-07-22 at 23 03 16" src="https://user-images.githubusercontent.com/9209644/126709209-8ccef1e3-e061-4986-8682-172c97a97cae.png">

Notice how skewed it is. The two friends flipped coins; each had the same chance of winning as the other. We could expect that there would be some flipping back and forth in the beginning (or the end, as it turns out, by way of symmetry), and there was. But it stopped in the very first beat of the process. The rest of the score was 99% in person A's favor. So think about which systems we can expect to fall for this unintuitive probabilistic compounding. 
If you want some good reading, I suggest [Replication Crisis](https://en.wikipedia.org/wiki/Replication_crisis).
