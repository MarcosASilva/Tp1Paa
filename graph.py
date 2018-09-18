import pandas as pd
import matplotlib.pyplot as plt
a = pd.read_csv("teste2.csv")
a = a.sort_values(by='TamanhoDaEntrada')
a1 = a[a['TamanhoDaEntrada']==10]
a2 = a[a['TamanhoDaEntrada']==100]
a3 = a[a['TamanhoDaEntrada']==1000]
a4 = a[a['TamanhoDaEntrada']==10000]
a5 = a[a['TamanhoDaEntrada']==100000]
a1plt = a1.drop('TamanhoDaEntrada',axis=1).mean().plot(kind="bar",figsize=(8,8),subplots=True)
fig = a1plt[0].get_figure()
fig.savefig("plotn10.png")
a2plt = a2.drop('TamanhoDaEntrada',axis=1).mean().plot(kind="bar",figsize=(8,8),subplots=True)
fig2 = a2plt[0].get_figure()
fig2.savefig("plotn100.png")
a3plt = a3.drop('TamanhoDaEntrada',axis=1).mean().plot(kind="bar",figsize=(8,8),subplots=True)
fig3 = a3plt[0].get_figure()
fig3.savefig("plotn1000.png")
a4plt = a4.drop('TamanhoDaEntrada',axis=1).mean().plot(kind="bar",figsize=(8,8),subplots=True)
fig4 = a4plt[0].get_figure()
fig4.savefig("plotn10000.png")
a5plt = a5.drop('TamanhoDaEntrada',axis=1).mean().plot(kind="bar",figsize=(8,8),subplots=True)
fig5 = a5plt[0].get_figure()
fig5.savefig("plotn100000.png")



a.groupby('TamanhoDaEntrada').mean().to_csv('MediaTempoExecucao.csv')
a.drop('TamanhoDaEntrada',axis=1).describe().to_csv('DadosExecucao.csv')


