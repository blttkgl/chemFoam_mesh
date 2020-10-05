{
    rho = thermo.rho();
    forAll(rho,celli)
    {
        if (constProp == "volume")
        {
            scalar invW = 0.0;
            forAll(Y, i)
            {
                invW += Y[i][celli]/W[i];
            }

            Rspecific[celli] = 1000.0*constant::physicoChemical::R.value()*invW;

            p[celli] = rho0[celli]*Rspecific[celli]*thermo.T()[celli];
            rho[celli] = rho0[celli];
        }        
    }

}
