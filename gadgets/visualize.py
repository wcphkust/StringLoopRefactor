#!/usr/bin/python3
# --- Load GPyOpt
#from GPyOpt.methods import BayesianOptimization
import numpy as np
import os
import re
from subprocess import call, DEVNULL, Popen, PIPE
from sklearn.manifold import TSNE
import matplotlib.pyplot as plt


full_vocab = "MRCPNBZXEIFVS"

def vocabToVector(v):
  vector = []
  chrs = {elem: 0 for elem in full_vocab} 
  for c in v:
      if c.isupper():
          chrs[c] += 1
  for ch in full_vocab:
      vector.append(chrs[ch])
#  print(vector)
  return vector


def getData():
  subdirs = next(os.walk('.'))[1] 
  data = []
  for d in subdirs:
      m = re.search("exp-([A-Z0-9]+)-([0-9]+)s-([0-9]+)", d)
      if m:
          vocab, time, progsize = m.group(1), m.group(2), m.group(3)
          command="ls {}/*.prog | wc -l 2>&1".format(d)
          proc = Popen(command, stdout=PIPE, shell=True)
          (out,err) = proc.communicate()
          synthesized_programs = int(out.decode("utf-8"))
          data.append((vocabToVector(vocab), int(time), int(progsize), synthesized_programs, vocab))
  return np.array(data)


def prettyPrintVocab(v):
  vv = vocabToVector(v)
#  print(vv)
  return "".join([c + ("" if n == 1 else str(n)) for n, c in zip(vv, full_vocab) if n > 0])

data = getData()
#print(data)
vector, time, ps, synthesized_programs, vocab = (data[data[:,1] == 300, i] for i in range(5))
a = [b for b in vector]
vector = np.array(a)
print(vocab)

tsne = TSNE(n_iter=500, random_state=7653453, method='exact')
tsne_results = tsne.fit_transform(vector)
x,y = np.rollaxis(tsne_results,1)

a = plt.scatter(x,y, c=synthesized_programs)

for i, txt in enumerate(map(prettyPrintVocab, vocab)):
    plt.annotate(txt, (x[i], y[i]),ha='center', size=8)
plt.colorbar(a, label="Number of synthesized programs")
plt.axis('off')
plt.savefig('t-SNeG.pdf')

