#!/usr/local/bin/python
# --- Load GPyOpt
from GPyOpt.methods import BayesianOptimization
import numpy as np
import os
from subprocess import call, DEVNULL, Popen, PIPE


vocab = "MRCPNBZXEIFVS"

def snd(x): return x[1]
def fst(x): return x[0]

# --- Define your problem
def f(x): 
  TIME=300
  PROG_SIZE=7
  for bitvec in x:
      print(bitvec)
     # selected_vocab = list(map(fst,filter(snd, zip(vocab, bitvec))))
      selected_vocab = filter(snd, zip(vocab, bitvec))
      sv = [ r for char, num in selected_vocab for r in [char] + [ char + str(i) for i in range(2,int(num))]]
      
      print("-".join(sv))
      selected_vocab = sv
#      selected_vocab = "MRPNBZIF"
#      selected_vocab = "PNXF"

      gadgets = " ".join(selected_vocab)
      call(["make", "GADGETS={}".format(gadgets), 
                    "TIME={}".format(TIME), 
                    "PROG_SIZE={}".format(PROG_SIZE)],
#           stdout=DEVNULL,
#           stderr=DEVNULL
           )


      dirname="exp-{}-{}s-{}".format("".join(selected_vocab), TIME, PROG_SIZE)
      command="ls {}/*.prog | wc -l 2>&1".format(dirname)
      proc = Popen(command, stdout=PIPE, shell=True)
      (out,err) = proc.communicate()
      synthesized_programs = int(out.decode("utf-8"))
      print(synthesized_programs)
      return synthesized_programs

domainMax = None
try: 
  domainMax = int(os.environ['DOMAIN_MAX'])
  acquisition_type = os.environ['ACQUISITION']
except KeyError:
  domainMax = 2 if domainMax is None else domainMax
  acquisition_type = 'EI'


domain = [{'name': "var-" + gadget, 
           'type': 'discrete',
           'domain': tuple(range(0, domainMax))} for gadget in vocab ]
print(domain, acquisition_type)

myBopt = BayesianOptimization(f, domain,
                maximize=True, exact_feval = True,
                acquisition_optimizer_type='lbfgs', acquisition_type=acquisition_type)
myBopt.run_optimization(max_iter=35)
myBopt.save_report("report")
myBopt.save_evaluations("evals")
myBopt.plot_convergence("convergence.png")
