dtChem = chemistry.solve(runTime.deltaT().value());
forAll(rho,i)
{
    auto Qdot = chemistry.Qdot()()[i]/rho[i];
    integratedHeat[i] += Qdot * runTime.deltaT().value();
}
