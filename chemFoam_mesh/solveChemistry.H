dtChem = chemistry.solve(runTime.deltaT().value());
Qdot = chemistry.Qdot()()/rho;
integratedHeat += Qdot* runTime.deltaT().value();

