runTime.controlDict().lookup("adjustTimeStep") >> adjustTimeStep;
maxDeltaT = readScalar(runTime.controlDict().lookup("maxDeltaT"));
minDeltaT = readScalar(runTime.controlDict().lookup("minDeltaT"));
