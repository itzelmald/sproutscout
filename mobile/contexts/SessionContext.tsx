import React, { useEffect, useState } from 'react';
import { supabase } from '../lib/supabase';
import { Session } from '@supabase/supabase-js';

const AuthContext = React.createContext<{ session?: Session | null, isLoading: boolean }>({
  session: undefined,
  isLoading: true
});

// This hook can be used to access the user info.
export function useSession() {
  const value = React.useContext(AuthContext);
  if (process.env.NODE_ENV !== 'production') {
    if (!value) {
      throw new Error('useSession must be wrapped in a <SessionProvider />');
    }
  }

  return value;
}

export function SessionProvider(props: React.PropsWithChildren) {
    const [session, setSession] = useState<Session | null>()

    useEffect(() => {  
      supabase.auth.onAuthStateChange((_event, session) => {
        setSession(session)
      })
    }, [])

  return (
    <AuthContext.Provider
      value={{
        session,
        isLoading: session === undefined,
      }}>
      {props.children}
    </AuthContext.Provider>
  );
}
