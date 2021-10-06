from time import time

def typingErrors(prompt):
    global iwords

    words = prompt.split()
    errors = 0

    for i in range(len(iwords)):
        if i in (0, len(iwords)-1):
            if iwords[i] == words[i]:
                continue
            else:
                errors +=1
        else:
            if iwords[i] == words[i]:
                if (iwords[i+1] == words[i+1]) & (iwords[i-1] == words[i-1]):
                    continue
                else:
                    errors += 1
            else:
                errors += 1
    return errors

def typingSpeed(iprompt, stime, etime):
    global time
    global iwords

    iwords = iprompt.split()
    twords = len(iwords)
    speed = twords / time

    return speed

def timeElapsed(stime, etime):
    time = etime - stime

    return time

if __name__ == '__main__':
    prompt = "Hi, my name is Aman."
    print("Type this:- '", prompt, "'")

    input("press ENTER when you are ready!")

    stime = time()
    iprompt = input()
    etime = time()

    time = round(timeElapsed(stime, etime), 2)
    speed = typingSpeed(iprompt, stime, etime)
    errors = typingErrors(prompt)

    print("Total Time elapsed : ", time, "s")
    print("Your Average Typing Speed was : ", speed, "words / minute")
    print("With a total of : ", errors, "errors")